import os
import pandas as pd
import glob
import re
import matplotlib.pyplot as plt

# Define constants with original English names for algorithms
ALGORITHMS = ['HeapSortTimes', 'InsertSortTimes', 'InsertBinarySortTimes', 'QuickSortTimes']
DATA_TYPES = ['Int', 'Float']
ARRAY_ORDERS = ['', '33', '66', 'Desc', '100']  # Keep original names for internal use
FILE_SIZES = [5000, 10000, 20000, 40000, 60000, 80000, 100000]

# Dictionary for translating array order names to Polish for the chart
ARRAY_ORDERS_TRANSLATED = {
    '': 'tablica losowa',
    '33': 'tablica posortowana w 33%',
    '66': 'tablica posortowana w 66%',
    'Desc': 'tablica posortowana malejąco',
    '100': 'tablica posortowana rosnąco'
}

# Dictionary for translating algorithm names to Polish for the chart
ALGORITHMS_TRANSLATED = {
    'HeapSortTimes': 'Sortowanie przez kopcowanie - czas wykonania',
    'InsertSortTimes': 'Sortowanie przez wstawianie - czas wykonania',
    'InsertBinarySortTimes': 'Sortowanie przez wstawianie binarne - czas wykonania',
    'QuickSortTimes': 'Sortowanie szybkie - czas wykonania'
}

def extract_data_from_xlsx_files(input_dir):
    """
    Extract data from all xlsx files in the input directory
    """
    # Get all xlsx files
    all_files = glob.glob(os.path.join(input_dir, "*.xlsx"))

    # Create an empty DataFrame to store all data
    all_data = pd.DataFrame()

    # Process each file
    for file in all_files:
        try:
            # Read xlsx file
            df = pd.read_excel(file)
            print(f"Successfully read {file}")
            # Append to the combined DataFrame
            all_data = pd.concat([all_data, df], ignore_index=True)
        except Exception as e:
            print(f"Error reading {file}: {e}")

    # Print a sample of data to debug
    if not all_data.empty:
        print("\nSample data:")
        print(all_data.head())
        print(f"\nColumns: {all_data.columns.tolist()}")
    else:
        print("No data was read from the files!")

    return all_data

def parse_table_name(table_name):
    """
    Parse the table name to extract data type and array order
    Example: RandomFloatDesc -> ('Float', 'Desc')
    """
    # Handle non-string values
    if not isinstance(table_name, str):
        print(f"Warning: Table name is not a string: {table_name}")
        return None, None

    # Updated pattern to match: Random(Int|Float)(33|66|Desc|100|Sorted)?
    pattern = r'Random(Int|Float)(33|66|Desc|100|Sorted)?'
    match = re.match(pattern, table_name.strip())

    if match:
        data_type = match.group(1)  # Int or Float
        array_order = match.group(2) if match.group(2) else ""  # Default to empty string if not matched
        return data_type, array_order
    else:
        print(f"Warning: Could not parse table name: {table_name}")
        return None, None

def save_table_as_image(table_data, filename):
    """
    Save the table as a JPG image, with only Polish column names displayed.
    Removes columns with all NaN values before rendering.
    """
    fig, ax = plt.subplots(figsize=(12, 8))
    ax.axis('tight')
    ax.axis('off')

    # Modify column names to use translated Polish names
    table_data.columns = [ARRAY_ORDERS_TRANSLATED.get(col, col) for col in table_data.columns]

    # Remove columns where all values are NaN
    table_data = table_data.dropna(axis=1, how='all')

    # Render table with modified columns and without NaN-only columns
    ax.table(cellText=table_data.values, colLabels=table_data.columns, loc='center', cellLoc='center')

    # Save the figure as a JPG file
    plt.savefig(filename, format='jpg', bbox_inches='tight', dpi=300)
    plt.close()

def create_plots_and_tables(data, output_dir):
    """
    Create plots and tables for each algorithm and data type combination
    """
    # Create output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)

    # Process each algorithm and data type combination
    for algorithm in ALGORITHMS:
        for data_type in DATA_TYPES:
            print(f"\nProcessing {algorithm} - {data_type}...")

            # Create a figure for this algorithm and data type
            fig, ax = plt.subplots(figsize=(12, 8))
            ax.set_title(f"{ALGORITHMS_TRANSLATED[algorithm]} {data_type}", fontsize=16)  # Translate the algorithm name
            ax.set_xlabel("Rozmiar tablicy", fontsize=12)  # Polish label for x-axis
            ax.set_ylabel("Średni czas (ms)", fontsize=12)  # Polish label for y-axis
            ax.grid(True)

            # Create a DataFrame to store the table data
            table_data = pd.DataFrame(columns=['Array Size'] + [order if order else 'tablica losowa' for order in ARRAY_ORDERS])

            # Flag to check if any data was found for this combination
            has_data = False

            # Process each array order
            for array_order in ARRAY_ORDERS:
                # Find matching rows for this algorithm, data type, and array order
                matching_rows = []
                for _, row in data.iterrows():
                    table = row.get('Table', '')
                    file = row.get('File', '')
                    dt, ao = parse_table_name(table)
                    algo_from_file = str(file).replace('.csv', '').strip()

                    # Check if this row matches the criteria
                    if (
                            dt == data_type and
                            ao == array_order and
                            algo_from_file == algorithm
                    ):
                        matching_rows.append(row)

                # Create a DataFrame from the matching rows
                order_data = pd.DataFrame(matching_rows)

                # Skip if no data found
                if order_data.empty:
                    print(f"  No data found for {ARRAY_ORDERS_TRANSLATED.get(array_order, 'tablica losowa')}")
                    continue

                print(f"  Found {len(order_data)} rows for {ARRAY_ORDERS_TRANSLATED.get(array_order, 'tablica losowa')}")
                has_data = True

                # Extract x and y values for plotting
                x_values = order_data['FileName'].astype(int)
                y_values = order_data['Avg_Time_ms']

                # Plot points connected by lines
                label = ARRAY_ORDERS_TRANSLATED.get(array_order, 'tablica losowa')
                ax.plot(x_values, y_values, marker='o', label=label, linestyle='-', markersize=8)

                # Add data to table
                for size in FILE_SIZES:
                    size_data = order_data[order_data['FileName'] == size]
                    if not size_data.empty:
                        if size not in table_data['Array Size'].values:
                            new_row = {'Array Size': size}
                            table_data = pd.concat([table_data, pd.DataFrame([new_row])], ignore_index=True)

                        # Find row index
                        row_idx = table_data[table_data['Array Size'] == size].index[0]

                        # Add value to table
                        table_data.loc[row_idx, ARRAY_ORDERS_TRANSLATED.get(array_order, 'tablica losowa')] = size_data['Avg_Time_ms'].values[0]

            # Only add legend and save if we have data
            if has_data:
                # Sort table by array size
                table_data = table_data.sort_values(by='Array Size')

                # Add legend with title 'uporządkowanie tablicy'
                ax.legend(title="uporządkowanie tablicy")

                # Save plot
                plot_filename = os.path.join(output_dir, f"{algorithm}_{data_type}.png")
                plt.savefig(plot_filename)

                # Save table to CSV
                table_filename = os.path.join(output_dir, f"{algorithm}_{data_type}.csv")
                table_data.to_csv(table_filename, index=False)

                # Save table as image (JPG)
                table_image_filename = os.path.join(output_dir, f"{algorithm}_{data_type}_table.jpg")
                save_table_as_image(table_data, table_image_filename)

                print(f"Created {algorithm}_{data_type} plot, table, and table image")
            else:
                print(f"No data found for {algorithm} - {data_type}, skipping output files")

            plt.close()

def main():
    # Define input and output directories
    input_dir = "../ReportData/PreparedDataPointChart"  # Directory containing xlsx files
    output_dir = "../ReportData/ChartFiles"  # Directory to save output files

    # Extract data from xlsx files
    print("Reading data from xlsx files...")
    all_data = extract_data_from_xlsx_files(input_dir)

    # Create plots and tables
    print("Creating plots and tables...")
    create_plots_and_tables(all_data, output_dir)

    print(f"Done! Output files saved to {output_dir}")

# Run the program
if __name__ == "__main__":
    main()

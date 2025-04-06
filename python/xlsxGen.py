import os
import pandas as pd
import platform

def combine_csvs_to_excel_with_summary(parent_folder, output_excel):
    combined_data = []

    for root, dirs, files in os.walk(parent_folder):
        for file in files:
            if file.lower().endswith('.csv'):
                file_path = os.path.join(root, file)
                table_name = os.path.basename(os.path.dirname(file_path))
                file_name = os.path.basename(file)

                try:
                    df = pd.read_csv(file_path)

                    # Save original column names
                    original_columns = df.columns

                    # Normalize headers for safe comparison
                    normalized_cols = [col.strip().lower() for col in df.columns]
                    df.columns = normalized_cols

                    # Check for required columns
                    if 'index' in df.columns and 'time(ms)' in df.columns:
                        df = df[['index', 'time(ms)']]  # Only keep needed columns
                        df.columns = ['Index', 'Time(ms)']  # Rename to match original format
                        df['Table'] = table_name
                        df['File'] = file_name
                        combined_data.append(df)
                    else:
                        print(f"⚠️ Skipped (missing 'Index' or 'Time(ms)'): {file_path}")
                        print(f"    Found columns: {list(original_columns)}")

                except Exception as e:
                    print(f"❌ Error reading {file_path}: {e}")

    if not combined_data:
        print("🚫 No valid CSV files found to combine.")
        return

    # Combine everything
    result_df = pd.concat(combined_data, ignore_index=True)

    # Summary by Table and File
    summary_df = (
        result_df
        .groupby(['Table', 'File'])
        .agg(
            Rows=('Index', 'count'),
            Avg_Time_ms=('Time(ms)', 'mean')
        )
        .reset_index()
        .sort_values(by=['Table', 'File'])
    )

    # Write to Excel
    try:
        with pd.ExcelWriter(output_excel, engine='xlsxwriter') as writer:
            result_df.to_excel(writer, index=False, sheet_name='Combined Data')
            summary_df.to_excel(writer, index=False, sheet_name='Summary')
        print(f"✅ Excel file created: {output_excel}")
    except Exception as e:
        print(f"❌ Failed to write Excel file: {e}")


# 🧪 Example usage:
# Replace with your actual folder path
parent_folder = '../10000'
output_excel = '../ReportData/10000.xlsx'

if(platform.system() != 'Linux'):
    parent_folder = r'C:\Users\Filip Kwiek\Desktop\AIZO-p1\100000'
    output_excel = r'C:\Users\Filip Kwiek\Desktop\AIZO-p1\ReportData\100000.xlsx'

combine_csvs_to_excel_with_summary(parent_folder, output_excel)


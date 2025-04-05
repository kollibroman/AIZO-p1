import pandas as pd
import re
import os

def process_summary_and_create_tables(files, output_dir):
   # Create output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)
    
    # Dictionary to store combined data for each unique (Table, File) combination
    combined_data = {}
    
    # Iterate through each file in the files collection
    for file in files:
        try:
            # Extract the numeric part from the file name using regex
            file_number = re.search(r'\d+', file).group()
            # Convert file number to integer
            file_number_int = int(file_number)
            
            # Load the Excel file
            print(f"Processing file: {file}")
            xl = pd.ExcelFile(file)
            # Read the Summary sheet to get Table and File details
            summary_df = xl.parse('Summary')
            
            # Iterate through each row in the summary dataframe
            for _, row in summary_df.iterrows():
                table_name = row['Table']
                file_value = row['File']  # The 'File' column value from the summary sheet
                
                # Create a unique key for this (Table, File) combination
                key = (table_name, file_value)
                
                # If this key doesn't exist in our dictionary yet, create it
                if key not in combined_data:
                    combined_data[key] = []
                
                # Add the row data with the file_number to the appropriate group
                row_copy = row.copy()
                row_copy['FileName'] = file_number_int  # Store as integer
                combined_data[key].append(row_copy)
                
            print(f"✅ Finished processing {file}")
        
        except Exception as e:
            print(f"❌ Error processing {file}: {e}")
    
    # Write each combined data set to a separate Excel file
    for (table_name, file_value), rows in combined_data.items():
        try:
            # Convert the list of rows to a DataFrame
            df = pd.DataFrame(rows)
            
            # Create a valid filename
            safe_table_name = re.sub(r'[\\/*?:"<>|]', "_", table_name)  # Replace invalid filename chars
            safe_file_value = re.sub(r'[\\/*?:"<>|]', "_", str(file_value))
            output_filename = f"{safe_table_name}_{safe_file_value}.xlsx"
            output_filepath = os.path.join(output_dir, output_filename)
            
            # Check for Avg_Time_ms column
            has_avg_time = 'Avg_Time_ms' in df.columns
            
            # Sort the DataFrame by FileName for proper chart
            df = df.sort_values(by='FileName')
            
            # Write the data to a new Excel file
            with pd.ExcelWriter(output_filepath, engine='xlsxwriter') as writer:
                workbook = writer.book
                sheet_name = 'Data'
                
                df.to_excel(writer, index=False, sheet_name=sheet_name)
                worksheet = writer.sheets[sheet_name]
                
                # Create a chart if Avg_Time_ms column exists
                if has_avg_time:
                    # Make sure we have enough data points for a meaningful chart
                    if len(df) > 1:
                        # Get column indices for FileName and Avg_Time_ms
                        filename_col = df.columns.get_loc('FileName') + 1  # +1 because Excel is 1-indexed
                        avg_time_col = df.columns.get_loc('Avg_Time_ms') + 1  # +1 because Excel is 1-indexed
                        
                        # Create a scatter chart with straight lines connecting the points
                        # Ensure we're creating the chart correctly
                        try:
                            chart = workbook.add_chart({'type': 'scatter'})
                            
                            if chart is None:
                                raise ValueError("Failed to create chart object")
                                
                            # Add line series
                            chart.add_series({
                                'name':       'Avg_Time_ms',
                                'categories': [sheet_name, 1, filename_col - 1, len(df), filename_col - 1],  # FileName column (X-axis)
                                'values':     [sheet_name, 1, avg_time_col - 1, len(df), avg_time_col - 1],  # Avg_Time_ms column (Y-axis)
                                'marker':     {'type': 'circle', 'size': 7},
                                'line':       {'width': 1.5}  # Add a line connecting the points
                            })
                            
                            # Set chart title and labels
                            chart.set_title({'name': f'{table_name} - {file_value} Performance'})
                            chart.set_x_axis({'name': 'File Number'})
                            chart.set_y_axis({'name': 'Average Time (ms)'})
                            chart.set_style(11)  # Add a nice style
                            
                            # Insert the chart into the worksheet
                            worksheet.insert_chart('K2', chart, {'x_scale': 1.5, 'y_scale': 1.5})
                            
                        except Exception as e:
                            print(f"⚠️ Error creating chart in {output_filepath}: {e}")
                    else:
                        print(f"⚠️ Not enough data points for chart in {output_filepath}")
                else:
                    print(f"⚠️ No Avg_Time_ms column found in data for {output_filepath}")
                
            print(f"✅ Created file: {output_filepath}")
        
        except Exception as e:
            print(f"❌ Error processing table {table_name}_{file_value}: {e}")
    
    print(f"✅ All tables and charts have been written to separate files in: {output_dir}")


# 🧪 Example usage:
files = [
    r'..\ReportData\5000.xlsx',
    r'..\ReportData\10000.xlsx',
    r'..\ReportData\20000.xlsx',
    r'..\ReportData\40000.xlsx',
    r'..\ReportData\60000.xlsx',
    r'..\ReportData\80000.xlsx',
    r'..\ReportData\100000.xlsx'
]

output_excel = r'..\ReportData\PreparedDataPointChart'

process_summary_and_create_tables(files, output_excel)

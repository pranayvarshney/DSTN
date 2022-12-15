#!/bin/bash

# Set the directory where the files to be compressed are located
source_dir="/path/to/files/to/compress"

# Set the directory where the compressed files should be saved
target_dir="/path/to/compressed/files"

# Set the filename for the compressed file
today=$(date +%Y-%m-%d)
filename="$today-backup.bz2"

# Compress the files in the source directory and save the compressed file in the target directory
pbzip2 -c -z3 "$source_dir" > "$target_dir/$filename"

# Schedule a cron job to run the script at midnight every day
#(crontab -l 2>/dev/null; echo "0 0 * * * $PWD/$0") | crontab -

#!/bin/bash

# Set the directory where the files to be compressed are located
source_dir="/home/pranay/Documents/DSTN/assignments/final_proj/dstn-geofen-storage/data"

# Set the directory where the compressed files should be saved
target_dir="/home/pranay/Documents/DSTN/assignments/final_proj/dstn-geofen-storage/compressed"

# Set the filename for the compressed file
today=$(date +%Y-%m-%d)
filename="$today.bz2"

# Compress the files in the source directory and save the compressed file in the target directory
pbzip2 -c -z3 "$source_dir/$today" > "$target_dir/$filename"

# Schedule a cron job to run the script at midnight every day
#(crontab -l 2>/dev/null; echo "0 0 * * * $PWD/$0") | crontab -
#30 23 * * * /path/compresssion.sh

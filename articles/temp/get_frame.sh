
video=$1
start_time=$2
screenshot_path=$3

ffmpeg -i $video -y -f  image2  -ss $start_time -vframes 1  $screenshot_path

# run_hls.tcl - CORRECTED VERSION
# Each encoding has its own testbench

puts "========================================"
puts "HLS - Corrected Testbench Structure"
puts "========================================"

# ============================================================
# PROJECT 1: Rate Encoding
# ============================================================
puts "\n[1/3] Rate Encoding..."

open_project snn_rate_encoding
set_top rate_encoding

add_files ../src/encoding.cpp
add_files ../src/encoding.h
add_files -tb ../src/testbench_rate.cpp
add_files -tb ../data/mnist_test_images.dat

open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default

puts "  Running C simulation..."
csim_design -clean

puts "  Running synthesis..."
csynth_design

close_project

# ============================================================
# PROJECT 2: Latency Encoding
# ============================================================
puts "\n[2/3] Latency Encoding..."

open_project snn_latency_encoding
set_top latency_encoding

add_files ../src/encoding.cpp
add_files ../src/encoding.h
add_files -tb ../src/testbench_latency.cpp
add_files -tb ../data/mnist_test_images.dat

open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default

puts "  Running C simulation..."
csim_design -clean

puts "  Running synthesis..."
csynth_design

close_project

# ============================================================
# PROJECT 3: Delta Encoding
# ============================================================
puts "\n[3/3] Delta Encoding..."

open_project snn_delta_encoding
set_top delta_encoding

add_files ../src/encoding.cpp
add_files ../src/encoding.h
add_files -tb ../src/testbench_delta.cpp
add_files -tb ../data/mnist_test_images.dat

open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default

puts "  Running C simulation..."
csim_design -clean

puts "  Running synthesis..."
csynth_design

close_project

puts "\n========================================"
puts "Complete! Check:"
puts "  snn_rate_encoding/solution1/csim/report/"
puts "  snn_latency_encoding/solution1/csim/report/"
puts "  snn_delta_encoding/solution1/csim/report/"
puts "========================================"

exit
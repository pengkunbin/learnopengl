rm -rf build
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=/usr/local/include ..
make 
./learnopengl
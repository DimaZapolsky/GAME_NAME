mkdir build
cd build
cmake ..
cmake --build .
cp ./Game ../Game
cd ..
rm -rf ./build*

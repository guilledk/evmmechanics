# evm mechanics

Based on eosmechanics contract used to simulate evm related events

To build:

    docker run \
        -it \
        --rm \
        --mount type=bind,source="$(pwd)",target=/root/target \
        guilledk/py-leap:cdt-4.0.1 \
        bash -c "mkdir -p build && cd build && cmake .. && make"

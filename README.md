# Zephyr Pinetime Demo Application

This repository contains a Zephyr application that demos that hardware 
of the pinetime smartwatch. The main purpose of this application is to 
demonstrate all the hardware working and as an example for how to use 
the Zephyr drivers for the hardware.

This repository refers to the [Zephyr main tree][zephyr], which is the 
development branch. The goal is to have as much drivers upstreamed, with
the in-development drivers in this repository. 

[zephyr]: https://github.com/zephyrproject-rtos/zephyr

## Getting Started

Before getting started, make sure you have a proper Zephyr development
environment. You can follow the official
[Zephyr Getting Started Guide](https://docs.zephyrproject.org/latest/getting_started/index.html).

### Initialization

The first step is to initialize the workspace folder (``my-workspace``) where
the ``example-application`` and all Zephyr modules will be cloned. You can do
that by running:

```shell
# initialize my-workspace for the zephyr-pinetime-demo (main branch)
west init -m https://github.com/caspermeijn/zephyr-pinetime-demo --mr main my-workspace
# update Zephyr modules
cd my-workspace
west update
```

### Build & Run

The application can be built by running:

```shell
cd demo-application
west build -s app
```

Then you can flash the application by running:
```shell
west flash
```

You can start a debug session by running:
```shell
west build -s app -- -DOVERLAY_CONFIG=semihosting.conf
west debug --tool-opt=-S
```

This will build the application with semihosting enabled.
Then it will start GDB. Choose `c` to start the application. 
The semihosting output is visible on telnet port 4444.

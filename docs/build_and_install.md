

## Install 

To install the lib just copy the [Amalgamation](https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.1.002/BearHttpsClientOne.c) into your project and include it in your code:
```c
#include "BearHttpsClientOne.c"
```


If  you are on Linux, you can download the lib with:
```bash
curl -L https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.1.002/BearHttpsClientOne.c -o BearHttpsClientOne.c
```

## Compile on Linux

To compile the lib in **Linux** you can use the following command:
```bash
gcc main.c -o your_output.out
```

## Compile on Windows

To compile the lib in **Windows** you can use the following commands

With Microsoft Visual C:
```cmd
cl.exe examples\example_simple.c /Fe:bin\example_simple.exe
```

With mingw64:
```bash
i686-w64-mingw32-gcc examples\example_simple.c -o bin\example_simple.exe -lws2_32
```

### Build from scratch
For build from scrach, clone these repo and run:
```bash
sh build_dependencies.sh
sh build.sh 
```

### If you want to reinstall dependneices
```bash
sh installldependencies.sh 
```

### Mocking dependencies or dependencies implementations 

The following defines toggle dependencies or just the definitions.
It is useful for  working with dynamic compilation or mocking dependencies.
```c
// unallow universal socket definition
#define BEARSSL_HTTPS_MOCK_UNIVERSAL_SOCKET_DEFINE

// unallow universal socket implementation
#define BEARSSL_HTTPS_MOCK_BEARSSL_DEFINE

// unallow cjson at all
// NOTE: Hiding CJSON will force the lib to use **get_addrinfo** which
// can leak memory in some cases.
#define BEARSSL_HTTPS_MOCK_CJSON

// unallow cjson definition
#define BEARSSL_HTTPS_MOCK_CJSON_DEFINE

//import the lib only after the flags
#include "BearHttpsClientOne.c"
``` 

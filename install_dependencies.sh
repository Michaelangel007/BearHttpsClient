rm -rf dependencies
mkdir dependencies


### Required Tools 
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.020/darwin.c -o dependencies/darwin.c

### Project Dependencies

curl -L https://github.com/OUIsolutions/BearSslSingle-Unit/releases/download/0.0.3/BearSSLSingleUnit.h -o dependencies/BearSSLSingleUnit.h 
curl -L https://github.com/OUIsolutions/BearSslSingle-Unit/releases/download/0.0.3/BearSSLSingleUnit.c -o dependencies/BearSSLSingleUnit.c
curl -L https://raw.githubusercontent.com/DaveGamble/cJSON/refs/tags/v1.7.18/cJSON.c -o dependencies/cJSON.c
curl -L https://raw.githubusercontent.com/DaveGamble/cJSON/refs/tags/v1.7.18/cJSON.h -o dependencies/cJSON.h
curl -L https://github.com/SamuelHenriqueDeMoraisVitrio/UniversalSocket/releases/download/v0.2.4/UniversalSocket.c -o dependencies/UniversalSocket.c
curl -L https://github.com/SamuelHenriqueDeMoraisVitrio/UniversalSocket/releases/download/v0.2.4/UniversalSocket.h -o dependencies/UniversalSocket.h

curl -L https://curl.se/ca/cacert.pem -o dependencies/cacert.pem

### Creating BearSSL Trust Anchors
cd dependencies
git clone https://www.bearssl.org/git/BearSSL

rm -rf BearSSL/.git
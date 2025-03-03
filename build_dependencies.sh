gcc dependencies/darwin.c -o darwin.out
cd dependencies/BearSSL
make
cd ../..
chmod +x dependencies/BearSSL/build/brssl
#call the brssl tool to generate the trust anchors 
./dependencies/BearSSL/build/brssl ta dependencies/cacert.pem > dependencies/BearSSLTrustAnchors.h
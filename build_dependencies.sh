
#se building trusted anchors
cd dependencies/BearSSL
make
cd ../..
chmod +x dependencies/BearSSL/build/brssl
./dependencies/BearSSL/build/brssl ta dependencies/cacert.pem > dependencies/BearSSLTrustAnchors.h
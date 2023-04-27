

#ifndef ENCRYPTDEMO_MYMD5_H
#define ENCRYPTDEMO_MYMD5_H

#include <string>
#include <stdio.h>
#include <vector>

using namespace std;



class Md5Utils{
public:

    typedef unsigned int size_type; // must be 32bit

    Md5Utils();
    Md5Utils(const char * text);
    Md5Utils(const std::string& text);

    //Md5Utils(ifstream& FilePath);
    void update(const unsigned char *buf, size_type length);
    void update(const char *buf, size_type length);
    Md5Utils& finalize();
    std::string hexdigest() const;
    static  std::string MD5(std::string str);
    static  std::string MD5(char* str);

    friend std::ostream& operator<<(std::ostream&, Md5Utils md5);

private:
    void init();
    typedef unsigned char uint1; //  8bit
    typedef unsigned int uint4;  // 32bit
    enum { blocksize = 64 }; // VC6 won't eat a const static int here

    void transform(const uint1 block[blocksize]);
    static void decode(uint4 output[], const uint1 input[], size_type len);
    static void encode(uint1 output[], const uint4 input[], size_type len);

    bool finalized;
    uint1 buffer[blocksize]; // bytes that didn't fit in last 64 byte chunk
    uint4 count[2];   // 64bit counter for number of bits (lo, hi)
    uint4 state[4];   // digest so far
    uint1 digest[16]; // the result

    // low level logic operations
    static inline uint4 F(uint4 x, uint4 y, uint4 z);
    static inline uint4 G(uint4 x, uint4 y, uint4 z);
    static inline uint4 H(uint4 x, uint4 y, uint4 z);
    static inline uint4 I(uint4 x, uint4 y, uint4 z);
    static inline uint4 rotate_left(uint4 x, int n);
    static inline void FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);

};

#endif //ENCRYPTDEMO_MYMD5_H

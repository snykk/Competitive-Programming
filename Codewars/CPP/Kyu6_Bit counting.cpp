unsigned int countBits(unsigned long long n){
  int result = 0; 
  for (int i=63;i>=0;i--) { //63 is the maximum binary length of long long datatype
    //using betwise operator
    int j = n >> i; 
    if (j & 1) result += 1;
  }

//dude on the top
#include <limits>
#include <bitset>
inline constexpr unsigned int countBits(const unsigned long long n) noexcept {
  std::bitset<std::numeric_limits<unsigned long long>::digits> b(n);
  return b.count();
}
  return result;
}
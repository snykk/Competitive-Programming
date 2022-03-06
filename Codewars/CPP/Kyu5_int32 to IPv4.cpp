#include <string>
using namespace std;
std::string uint32_to_ip(uint32_t ip)
{
  string res = "";
  int temp;
  temp = ip/16777216;
  res += to_string(temp) + '.';
  ip %= 16777216;
  temp = ip/65536;
  res += to_string(temp) + '.';
  ip %= 65536;
  temp = ip/256;
  res += to_string(temp) + '.';
  ip %= 256;
  res += to_string(ip);
  return res;  
}

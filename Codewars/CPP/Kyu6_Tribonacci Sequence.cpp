using namespace std;
vector<int> tribonacci(vector<int> signature, int n)
{
  if (n <=3 ) return {signature.begin(), signature.begin()+n};
  int num1 = signature[0];
  int num2 = signature[1];
  int num3 = signature[2];
  int temporary = 0;
  vector<int> result = {signature.begin(), signature.end()};
  int inc = 0;
  while (inc < n-3) {
    temporary = num1+num2+num3;
    result.push_back(temporary);
    num1 = num2;
    num2 = num3;
    num3 = temporary;
    inc ++;
  }
  return result;
}

//guys on the top
std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    if(n<3){
       signature.resize(n);
    }
    for(unsigned int i = 3; i<n;i++){
      signature.push_back(signature[i-3]+signature[i-2]+signature[i-1]);
    }
    return signature;
}

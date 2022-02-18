#include <string>

std::string update_light(std::string current) {
  if (current == "green"){
    return "yellow";
  } else if(current == "yellow"){
    return "red";
  } else{
    return "green";
  }
}
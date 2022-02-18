int twice_as_old(int dad, int son) {
  int result;
  result = dad-2*son;
  if (result>=0){
    return result;
  }
  return 2*son-dad;
}
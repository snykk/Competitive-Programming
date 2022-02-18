std::string DNAtoRNA(std::string dna){
  for (int i;i<dna.length();i++) {
    if (dna[i] =='T') {
      dna[i] = 'U';
    }
  }
  return dna;
}


package kata

func DNAStrand(dna string) string {
	var result string
  mapHelper := map[string]string{
		"T": "A",
		"A": "T",
		"G": "C",
		"C": "G",
	}

	for _, char := range dna {
		result += mapHelper[string(char)]
	}

	return result
}

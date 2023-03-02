package kata

func ExpSum(n uint64) uint64 {
  checkpoint := make([]uint64, n+1)
  checkpoint[0] = 1
  for i := uint64(checkpoint[0]); i < n+1; i++ {
      for j := i; j < n+1; j++ {
          checkpoint[j] += checkpoint[j-i]
      }
  }
  return checkpoint[n]
}

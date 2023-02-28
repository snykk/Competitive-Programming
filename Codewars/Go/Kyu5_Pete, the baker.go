package kata

import (
  "math"
)


func Cakes(recipe, available map[string]int) int {
	var result float64 = math.MaxFloat64
	var misc = []float64{}
	for keyR, valR := range recipe {
		valA, ok := available[keyR]
		if !ok {
			return 0
		}

		avail := math.Floor(float64(valA) / float64(valR))
		misc = append(misc, avail)
	}

	for _, item := range misc {
		if item < result {
			result = item
		}
	}

	return int(result)
}

#!/bin/bash

git ls-files --others --exclude-standard -z | while IFS= read -r -d '' file; do
  git add "$file"
  filename="${file%.*}"
  git commit -m "$filename"
done

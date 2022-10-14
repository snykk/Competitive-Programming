var="$1"

for i in $(seq 1 ${#var}); do
  if [[ "${var:i-1:1}"  != [[:space:]] ]] 
  then
    echo -n "${var:i-1:1}"
  fi
done

function valid_spacing($s) {
 if ($s =="") return true;
 if ($s == " ") return false;
 if ($s[0] == " " || $s[-1] == " ") return false;
 $lst = explode(" ",$s);
 while (list($key, $value) = each($lst)) { 
   if ($value == ""){
     return false;
   }
 }
 return true;
}

//dude on the top
function valid_spacing($str) {
  return !preg_match("/^ |  | $/", $str);
}

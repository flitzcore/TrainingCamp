<?php
    function removeChar($target,$charToRemove){
  
        $pos = strpos($target, $charToRemove);
        if ($pos !== false) {
            $target = substr_replace($target, '', $pos, 1);
        }
        return $target;
    }
    function findAnagram($s,$p){
        $sLength=strlen($s);
        $pLength=strlen($p);
        $resultPointer=0;
        $result=[];
        for($left=0;$left<$sLength;$left++){

            $window=substr($s,$left,$pLength);
            if(strlen($window)<$pLength){
                break;
            }
         
            for($i=0;$i<$pLength;$i++){
                $window=removeChar($window,$p[$i]);
            }
            if(strlen($window)==0){
               
                $result[$resultPointer]=$left;
                $resultPointer++;
            }
        }
        return $result;

    }
   
    print_r(findAnagram("abab", "ab")); 

?>
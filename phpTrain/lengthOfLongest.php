<?php

function lengthOfLongestSubstring($str) {
    $hashmap=array();
    $maxLength=0;
    $left=0;
    $right=0;
    while($right<strlen($str)){
       
       if(isset($hashmap[$str[$right]])){
        
        // remove the first item in the hashmap
        unset($hashmap[$str[$left]]);
        $left++;
       }
       else{
        $hashmap[$str[$right]]=1;
        
       }
        $right++;
         // get hashmap size
         $hashmapSize=count($hashmap);
         if($hashmapSize>$maxLength){
    
             $maxLength=$hashmapSize;
         }
    }
    return $maxLength;
}

echo lengthOfLongestSubstring("pwwkew");

?>
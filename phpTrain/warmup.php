<?php
function firstNonRepeatingCharacter($str) {
    $hashmap=array();
    for ($i = 0; $i < strlen($str); $i++) {
        if (isset($hashmap[$str[$i]])) {
            $hashmap[$str[$i]]++;
        } else {
            $hashmap[$str[$i]] = 1;
        }
    }
    foreach ($hashmap as $key => $value) {
        if ($value === 1) {
            return $key;
        }
    }
    return null;
}

echo firstNonRepeatingCharacter("ayazbbccefdf");
?>
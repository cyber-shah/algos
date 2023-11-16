/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
    let output = [[]];
    let anagrams = [];

};

var isAnagram = function (input, test) {
    // Check if the lengths of the two strings are equal
    if (input.length !== test.length) {
        return false;
    }

    // Convert strings to arrays to simplify sorting
    var inputArray = input.split('');
    var testArray = test.split('');

    // Sort the arrays
    inputArray.sort();
    testArray.sort();

    // Compare the sorted arrays
    for (var i = 0; i < input.length; i++) {
        if (inputArray[i] !== testArray[i]) {
            return false;
        }
    }

    // If all characters match, it's an anagram
    return true;
};

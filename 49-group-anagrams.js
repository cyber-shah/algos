/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams0 = function (strs) {
	let output = [[]];
	output[0].push(strs[0]);

	// loop over all strings
	for (let i = 1; i < strs.length; i++) {
		const word = strs[i];
		var insert = false;
		// loop over all anagrams
		for (let j = 0; j < output.length; j++) {
			const anagram = output[j][0];
			if (isAnagram(word, anagram)) {
				output[j].push(word);
				insert = true;
			}
		}

		// none found to be anagram
		if (insert === false) {
			output.push([word]);
		}
	}
	return output;
};

var groupAnagrams = function (strs) {
    // Create a hashtable to store groups of anagrams
    const anagramGroups = {};

    // Loop over all strings
    for (let i = 0; i < strs.length; i++) {
        const word = strs[i];
        const sortedWord = word.split('').sort().join('');

        // Check if the sorted word is a key in the hashtable
        if (anagramGroups[sortedWord]) {
            anagramGroups[sortedWord].push(word);
        } else {
            // If not, create a new entry in the hashtable
            anagramGroups[sortedWord] = [word];
        }
    }

    // Convert the hashtable values to an array (the final result)
    const output = Object.values(anagramGroups);

    return output;
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


let strs = ["eat", "tea", "tan", "ate", "nat", "bat"];
console.log(strs);
console.log(groupAnagrams(strs));
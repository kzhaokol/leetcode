typedef int Index;
typedef int Addend;
typedef int Number;

typedef vector<Index> Indices;
typedef vector<Number> Numbers;
typedef unordered_map<Addend, Index> MapOfAddendToIndex;

Indices getIndicies(const Index & index1, const Index & index2) {
    auto first_element = min(index1, index2);
    auto second_element = max(index1, index2);
    return {first_element, second_element};
}

class Solution {
public:
    Indices twoSum(const Numbers & numbers, const Number target) {
        Indices indices;
        MapOfAddendToIndex mapOfAddendToIndex;
        
        for (Indices::size_type index = 0; index != numbers.size(); ++index) {
            auto addend = target - numbers[index];
            
            auto findItr = mapOfAddendToIndex.find(addend);
            if (findItr != mapOfAddendToIndex.end()) {
                return getIndicies(index, findItr->second);
            }
            
            mapOfAddendToIndex.emplace(make_pair(numbers[index], index));
        }

        
        return indices;
    }
};

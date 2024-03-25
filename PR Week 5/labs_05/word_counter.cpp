#include "word_counter.h"


namespace counts
{
    WordCounter::WordCounter():
        entries_{ }, // TODO 4: once you replace `std::array` with a dynamic array, initialize entries_ properly
        count_{ 0 },
        capacity_{ INITIAL_CAPACITY }
    {}

    // TODO 5: implement the destructor
    WordCounter::~WordCounter(){

    }

    // TODO 7: implement ensure_capacity function


    void WordCounter::increment(const std::string& word)
    {
        // if word already in counter, increment its count
        if (auto entry = find(word); entry)
        {
            ++entry->count;
        }
        else
        {
            if (count_ >= capacity_)
            {
                // TODO 8: implement ensure_capacity function and call it here
                // instead of returning
                return;
            }
            
            entries_[count_++] = { word, 1 };
        }
    }

    Entry* WordCounter::begin()
    {
        // TODO 3a: once you have removed `std::array` from the class, change to: 
         return entries_;

//        return entries_.begin();
    }

    const Entry* WordCounter::begin() const
    {
        // TODO 3b: once you have removed `std::array` from the class, change to: 
         return entries_;

//        return entries_.begin();
    }


    void WordCounter::decrement(const std::string& word)
    {
        if (auto entry = find(word); entry)
        {
            if (entry->count > 1)
            {
                --entry->count;
            }
        }
    }

    std::size_t WordCounter::get(const std::string& word) const
    {
        if (auto entry = find(word); entry)
        {
            return entry->count;
        }
        return 0;
    }


    Entry* WordCounter::end()
    {
        return begin() + count_;
    }

    const Entry* WordCounter::end() const
    {
        return begin() + count_;
    }
    

    std::size_t WordCounter::size() const
    {
        return count_;
    }
    
    Entry* WordCounter::find(const std::string& word)
    {
        for (std::size_t i = 0; i < count_; ++i)
        {
            if (entries_[i].word == word)
            {
                return &entries_[i];
            }
        }
        return nullptr;
    }
    
    const Entry* WordCounter::find(const std::string& word) const
    {
        for (std::size_t i = 0; i < count_; ++i)
        {
            if (entries_[i].word == word)
            {
                return &entries_[i];
            }
        }
        return nullptr;
    }
}
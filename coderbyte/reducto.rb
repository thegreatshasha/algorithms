def StringReduction(str)
  # Find an initial reducable count
  reducable = (0..str.length - 2).inject(0) {|sum, i| are_adjacent(str, i, i+1) ? sum + 1 : sum }
  
  while(str.length>1)
    max_reducable = 0
    max_reducable_pos = nil
    
    # Decide which position to slice at
    (0..str.length - 2).each do |i|
       # check if i n i+1 are adjacent
       if are_adjacent(str, i, i+1)
         temp_reducable = reducable
          # if i n i - 1 adjacent reducable--
          if are_adjacent(str, i-1, i)
            temp_reducable -= 1
          end
          
          if are_adjacent(str, i+1, i+2)
            temp_reducable -= 1
          end
          
          # Try reducing
          if are_adjacent(str, i-1, i+2) && reduce(str, i, i+1) != str[i+2]
            temp_reducable += 1
          end
          # if i+1 n i+2 are adjacent reducable--
          if temp_reducable > max_reducable
            max_reducable = temp_reducable
            max_reducable_pos = i
            printf "i-1: %d, i: %d, i+1: %d, i+2: %d\n", i-1, i, i+1, i+2
            #puts str[i-1], str[i], str[i+1], i-1, i, i+1
          end
        end
    end
  
    printf "max_reducable: %d, pos: %d\n", max_reducable, max_reducable_pos
    # Reduce at max_reducable_pos
    str = str[0..max_reducable_pos - 1] + reduce(str, max_reducable_pos, max_reducable_pos + 1)
    break 
    
  end
end

def are_adjacent(str, index1, index2)
  if(index1.between?(0, str.length-1) && index2.between?(0, str.length-1))
    str[index1] != str[index2]
  else
    false
  end
end

def reduce(str, index1, index2)
  return ("abc".chars - (str[index1]+str[index2]).chars.sort).join
end

# keep this function call here 
# to see how to enter arguments in Ruby scroll down   
StringReduction("abcbbc")  



#abcabc reducable: 5
#ccabc reducable: 3
#cbbc reducable: 2
#cccc reducable: 0

#aaabc reducable: 2
#abbbc reducable: 2













  
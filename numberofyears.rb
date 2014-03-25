class NumOfDays
	def initialize
		@weekmap = {
			"Monday"=> 0,
			"Tuesday"=> 1,
			"Wednesday"=> 2,
			"Thursday"=> 3,
			"Friday"=> 4,
			"Saturday"=> 5,
			"Sunday"=> 6
		}

		@monthmap = {
			"January" => 0,
			"February" => 1,
			"March" => 2,
			"April" => 3,
			"May" => 4,
			"June" => 5,
			"July" => 6,
			"August" => 7,
			"September" => 8,
			"October" => 9,
			"November" => 10,
			"December" => 11
		}
	end

	def iterate(day1, month1, year1, day2, month2, year2, initalweekday)
		# Increment day1 to sunday
		#binding.pry
		dayofweek = 1
		count = 0

		while lessthan(day1, month1, year1, day2, month2, year2)
			#puts "1, #{month1}, #{year1}: #{@weekmap.key(dayofweek)}"
			#binding.pry
			#binding.pry
			# Precondition, if sunday
			if dayofweek == 6
				puts "Sunday found"
				puts "1, #{month1}, #{year1}: #{@weekmap.key(dayofweek)}"
			
				count += 1

			end
			
			#puts "day: #{@weekmap.key(dayofweek)}, month: #{month1}, year: #{year1}"

			# Postcondition, increment
			#binding.pry
			diff = daysinmonth(month1, year1)
			#puts "Need to add: #{diff}, since it is #{month1}"
			dayofweek = (dayofweek + diff) % 7

			
			# Increase month
			if @monthmap[month1] == @monthmap.length - 1
				#binding.pry
				year1 += 1
				month1 = @monthmap.key(0)
			else
				month1 = @monthmap.key(@monthmap[month1] + 1)
			end

			# conditions to increment


		end

		puts "count is #{count}"
	end

	def lessthan(day1, month1, year1, day2, month2, year2)
		if year1 > year2
			#binding.pry
			false
		elsif @monthmap[month1] > @monthmap[month2]
			#binding.pry
			false
		elsif day1 > day2
			#binding.pry
			false
		else
			true
		end
	end
				
				

	def daysbetweenyears(date1, date2)
		day1, day2 =date1[0], date2[0]

		month1, month2 = date1[1], date2[1]
		
		year1, year2 = date1[2], date2[2]


		iterate(day1, month1, year1, day2, month2, year2, "Monday")
=begin
		days = 0

		days = days + daystillendofyear(day1, month1, year1) + daysfromstartofyear(day2, month2, year2)

		(year1 + 1 .. year2 - 1).each do |year|
			days += daysinyear(year)
		end

		days
=end

	end

	#test days in year works properly
	def daysinyear(year)
		# century test
		if leapyear?(year)
			366
		else
			365
		end
	end

	def daystillendofyear(day, month, year)
		days = 0
		days += daysinmonth(month, year) - day

		(@monthmap[month] + 1 .. 11).each do |monthindex|
			month = @monthmap.key(monthindex)
			days += daysinmonth(month, year)
		end

		days
	end

	def daysfromstartofyear(day, month, year)
		daysinyear(year) - daystillendofyear(day, month, year)
	end

	def leapyear?(year)
		if year.modulo(100).zero?
			
			if year.modulo(400).zero?
				true
			else
				false
			end
		else
			if year.modulo(4).zero?
				true
			else
				false
			end
		end
	end

	def daysinmonth(month, year)
		if ["February"].include? month
			if leapyear? year
				29
			else
				28
			end
		elsif ["September", "April", "June", "November"].include? month
			30
		else
			31
		end
	end

	def testdaysinyear(years)
	end

	def testdaysinmonth()
		@monthmap.keys.each do |month|
			puts "#{month} has #{daysinmonth(month, 2000)} days"
		end
	end
end

n = NumOfDays.new()
n.daysbetweenyears([1, "January", 1901], [31, "December", 2000])

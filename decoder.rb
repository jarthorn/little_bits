class Decoder
	def decode
		key = "?!BYCJDZXSMKFHWTIGEANQVOURPL"
		decoded = "?!ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		message = "ZOUD UD ?F EBANT EI! FBX QUVXJN UZ BXZW"
		(0..28).each do |i|
			result = ""
			message.split("").each do |c|
				if (c == " ")
					result << c
				else
					offset = (key.index(c) + i) % key.length
					result << decoded[offset]
				end
			end
			puts result
		end
    end
end

d = Decoder.new
d.decode
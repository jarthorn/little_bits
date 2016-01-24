class Decoder
	def decode
		key = "?!BYCJDZXSMKFHWTIGEANQVOURPL"
		decoded = "?!ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		message = "ZOUD UD ?F EBANT EI! FBX QUVXJN UZ BXZW"
		(0..28).each do |iteration|
			result = ""
			message.split("").each do |character|
				if (character == " ")
					result << character
				else
					offset = (key.index(character) + iteration) % key.length
					result << decoded[offset]
				end
			end
			puts result
		end
    end
end

Decoder.new.decode
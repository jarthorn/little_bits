#This is a companion class to illustrate some of the programming concepts
#behind a simple decoder ring activity. For details see:
#http://frugalfun4boys.com/2014/04/15/code-activity-kids-make-spy-decoder/
class Decoder
	attr_reader :key, :decoded
	def initialize
		@key = "?!BYCJDZXSMKFHWTIGEANQVOURPL"
		@decoded = "?!ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	end
	#encodes a message with a given wheel offset
    def encode(message, offset)
		result = ""
		message.split("").each do |character|
			if (character == " ")
				result << character
			else
				position = (@decoded.index(character) + offset) % key.length
				result << @key[position]
			end
		end
		return result
	end
	#decodes a message with a given wheel offset
	def decode(message, offset)
		result = ""
		message.split("").each do |character|
			if (character == " ")
				result << character
			else
				position = (@key.index(character) + offset) % key.length
				result << @decoded[position]
			end
		end
		return result
	end

	#This method will attempt to decode a message by trying all possible code wheel offsets
	def crack(message)
		(0..27).each do |offset|
			puts decode(message, offset)
		end
    end
end


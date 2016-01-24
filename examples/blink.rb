require 'little_bits'

cloud_bit = LittleBits::CloudBit.new('your-access-token', 'your-device-id')

# Set output to 100% for 3 seconds (3000 milliseconds)
cloud_bit.output(100, 3000)

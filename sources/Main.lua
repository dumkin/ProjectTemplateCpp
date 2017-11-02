
function pause()
	io.write("Enter to continue...\n")
	pause = io.read()
end

function main()
	for i=1,10 do
		print(i .. " % 2 = " .. mod(i, 2))
	end
	
	pause()
end
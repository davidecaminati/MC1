import Image

out = Image.new("RGB", (2000, 2000), "white")

#for line in open("myfile.txt"):
#x, y, name, pngfile = line.split()
x = 100
y = 100

pngfile = "C:\Users\dell\Desktop\centro\image___001.jpg"
out.paste(Image.open(pngfile), (int(x), int(y)))

out.save("C:\Users\dell\Desktop\out.png")
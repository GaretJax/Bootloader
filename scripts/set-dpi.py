from PIL import Image

import sys

if len(sys.argv) < 2:
    print "Usage: set-dpi.py dpi png-image1, png-image1,..."
    sys.exit(1)

dpi = int(sys.argv[1])
img = sys.argv[2:]

for i in img:
    Image.open(i).save(i, 'PNG', dpi=(dpi, dpi)) 
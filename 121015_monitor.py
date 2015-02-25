import time
from threading import *
import threading
from random import *

full = threading.Lock() 
empty= threading.Lock() 
pot= threading.Lock() 
oc= threading.Lock()
 
a=[]

def producer():
global a
time.sleep(randint(0,5))

if len(a) == 10: 
	print "\n Buffer is full"
	full.acquire()

pot.acquire()
full.acquire()
a.append(randint(0,10))
full.release()
print "\n Producer produced "+str(a[-1])

if empty.locked():
	empty.release()

pot.release()



def consumer():
global a
time.sleep(randint(0,15))
oc.acquire()

if len(s) < 1: 	
	print "\n Buffer is empty"
	empty.acquire()

empty.acquire()
print "\n consumer consumed "+str(a[-1])
del a[-1]

if empty.locked():
	empty.release()

if full.locked():
	full.release()
oc.release()



for p in range(20):
Thread(target=producer).start();
for c in range(4):
Thread(target=consumer).start();
for p in range(5):
Thread(target=producer).start();
for c in range(10):
Thread(target=consumer).start();

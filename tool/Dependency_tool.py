import json
import requests
from pprint import pprint
import Tkinter, tkFileDialog
import subprocess

root = Tkinter.Tk()
root.withdraw()

filename = tkFileDialog.askopenfilename()  # File Selector
#print(filename)
with open(filename,'r') as json_data:
	d=json.load(json_data)
	json_data.close()
	#pprint(d)
list_dependencies=d['Dependencies']        # reading File and storing into list
count1=0
text_file = open("Output_log.txt", "w")
for i in list_dependencies:
		#print(type(str(i)))
		p = subprocess.Popen('sudo pip install -Iv '+ str(i), shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
		out, err = p.communicate()
		#print(out)
		if out.find('DistributionNotFound')!=-1:
			text_file.write("%s : NO" % str(i))
		if out.find('Successfully installed')!=-1:
			text_file.write("%s : YES" % str(i))
			count1+=1
		text_file.write("\n");

		#print p.returncode
		#print(out,err,i)                            for checking Output Trace Uncomment this.

		#print (i,p.stderr)
		retval=p.wait()                           # for process to finish

text_file.close()
if count1==len(list_dependencies):
	print "success"
else:
	print "See Log File"
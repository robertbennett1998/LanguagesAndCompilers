#%%
out_file_path = ""
def get_enum():
	global out_file_path
	print("Please enter a file name to process: ")
	in_file = input()
	in_file_parts = in_file.split('/')
	out_file_path = in_file.replace(in_file_parts[-1], "")
	print(out_file_path)
	enum_file = open(in_file, "r")
	enum_file_contents = enum_file.read()
	enum_file.close()
	return enum_file_contents

#%%
#Imports

#%%
#Get file contents def
def get_enum():
	print("Please enter a file name to process: ")
	in_file_path = input()
	enum_file = open(in_file_path, "r")
	enum_file_contents = enum_file.read()
	enum_file.close()
	return enum_file_contents, in_file_path

#%% 
#Parse enum def
def parse_enum(enum_def):
	enum_def = enum_def.replace('\n', '')
	enum_def = enum_def.replace('\t', '')
	enum_def = enum_def.replace(' ', '')

	#remove the first line (this assumes the name is on the last line)
	open_brace_idx = enum_def.find('{')
	enum_def = enum_def[open_brace_idx + 1:len(enum_def)]
	#print(enum_def)

	#get the enum name
	close_brace_idx = enum_def.find('}')
	semi_colon_idx = enum_def.find(';')
	enum_name = enum_def[close_brace_idx + 1:semi_colon_idx]
	enum_def = enum_def[0:close_brace_idx]
	#print("\n\n", enum_name, "\n\n")

	next_equal_idx = enum_def.find('=')
	next_comma_idx = enum_def.find(',')
	#print("Equal:", next_equal_idx)
	#print("Comma:", next_comma_idx)
	while next_equal_idx != -1 and next_comma_idx != -1:
		#print(enum_def[next_equal_idx:next_comma_idx])
		enum_def = enum_def.replace(enum_def[next_equal_idx:next_comma_idx], "", 1)
		next_equal_idx = enum_def.find('=')
		next_comma_idx = enum_def.find(',')

	enum_entries = enum_def.split(",")
	#print(enum_entries)

	return enum_name, enum_entries

#%%
#Form print enum C
def create_print_enum_c(enum_name, enum_entries):
	print_enum_c_dec = "void Print" + enum_name + "Value(const " + enum_name + " value);"
	print_enum_c_def = "void Print" + enum_name + "Value(const " + enum_name + " value) \n{\n\tprintf(\"%s (%d)\\n\", NodeIdentifiersValueToString(value), (int)value);"
	print_enum_c_def += "\n}"

	return print_enum_c_dec, print_enum_c_def

#%%
#Form print enum C
def create_to_string_enum_c(enum_name, enum_entries):
	enum_to_string_c_dec = "const char* " + enum_name + "ValueToString(const " + enum_name + " value);"
	enum_to_string_c_def = "const char* " + enum_name + "ValueToString(const " + enum_name + " value)\n{\n\tswitch (value) \n\t{ \n\t\tdefault: \n\t\t\treturn \"Unknown value\";"
	for enum_entry in enum_entries:
		enum_to_string_c_def += "\n\t\tcase " + enum_entry + ": \n\t\t\treturn \"" + enum_entry + "\";"
	enum_to_string_c_def += "\n\t}\n}"

	return enum_to_string_c_dec, enum_to_string_c_def

#%%
#Write to file
def write_to_file(filepath, out):
	print("Writing enum utilities to " + filepath)
	out_file = open(filepath, "w+")
	out_file.write(out)
	out_file.close()

#%%
#main
enum_file_contents, enum_def_filepath = get_enum()
enum_name, enum_entries = parse_enum(enum_file_contents)

print_enum_c_dec, print_enum_c_def = create_print_enum_c(enum_name, enum_entries)
enum_to_string_c_dec, enum_to_string_c_def = create_to_string_enum_c(enum_name, enum_entries)

enum_def_filepath_parts = enum_def_filepath.split('/')
enum_def_filepath = enum_def_filepath.replace(enum_def_filepath_parts[-1], "", 1)

out_c = "//Declarations\n" + print_enum_c_dec + "\n" + enum_to_string_c_dec + "\n\n" + "//Definitions\n" +print_enum_c_def + "\n\n" + enum_to_string_c_def
out_c_filepath = enum_def_filepath + enum_name + "EnumUtils.c"
write_to_file(out_c_filepath, out_c)
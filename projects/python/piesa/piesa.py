with open(r"projects\python\piesa\roles.txt", "r", encoding="utf-8") as text:
    role_lines = {}
    i = 0
    
    for line in text:
        i += 1
        
        if line[0] == line[0].upper() and ": " in line:
            role, text = line.split(":")
            role = role.strip()
            text = text.strip()
            
            if role in role_lines:
                role_lines[role].append(str(i) + ") " + text)
            else:
                role_lines[role] = [str(i) + ") " + text]
        elif line.startswith(" "):
            text = line[5:]
            text = text.strip()
            role_lines[role].append(str(i) + ") " + text)
    
    result = ""
    for role in role_lines:
        result += role + ":\n"
        for i, line in enumerate(role_lines[role], 1):
            result += f"{line}\n"
        result += "\n"
    
    print(result)

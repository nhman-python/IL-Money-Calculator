import json

num = 1
# open the data fron the json file
with open('amaunt_israel_mony.json', 'r') as f:
    try:
        weight = json.load(f)
    except Exception as e:
        print(e)

def clac_again():
    again = input('you want to calculate again? (y/n)')
    if again != 'y':
        print('see you again...')
        exit()
def calculator(weight_input, type_corrency):
    if type_corrency == '1':
        total = weight_input / int(weight['0.1 agora'])
        return (f'Based on the data given the weight is equal to {total} ₪')
    elif type_corrency == '2':
        total = weight_input / int(weight['0.5 half'])
        return (f'Based on the data given the weight is equal to {total} ₪')
    elif type_corrency == '3':
        total = weight_input / int(weight['1 shekel'])
        return (f'Based on the data given the weight is equal to {total} ₪')
    elif type_corrency == '4':
        total = weight_input / int(weight['5 shekel'])
        return (f'Based on the data given the weight is equal to {total} ₪')
    elif type_corrency == '5':
        total = weight_input / int(weight['10 shekel'])
        return (f'Based on the data given the weight is equal to {total} ₪')
    else: return None



try:
    while True:
        weight_input = input('enter weight of corrency: ')
        if weight_input.isdigit():
            weight_input = int(weight_input)
            print()
            for i in weight:
                if i != "_comment":
                    print(f'{num}. {i}')
                    num += 1
        else:
            continue
        type_corrency = input('select corrency from the list: ')
        if type_corrency in ('1', '2', '3', '4', '5'):
            total = calculator(weight_input, type_corrency)
            if total:
                print(total)
                clac_again()

except (KeyboardInterrupt,  EOFError) as e:
    print('\nexit... good bay')
    exit()
except Exception as e:
    print(e)
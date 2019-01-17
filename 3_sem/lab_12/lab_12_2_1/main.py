from ctypes import c_int, POINTER
import ctypes

lib = ctypes.CDLL('my_lib.dll')

# void shift_array(int *arr, int n, int k)
_shift_array = lib.shift_array
_shift_array.argtypes = (POINTER(c_int), c_int, c_int)


# int *square_numbers(int *arr, int n, int *res_n)
_square_numbers = lib.square_numbers
_square_numbers.argtypes = (POINTER(c_int), c_int, POINTER(c_int))
_square_numbers.restype = POINTER(c_int)

def shift_array(array, k):
    n = len(array)
    arr = (c_int * n)(*array)
    _shift_array(arr, n, k)
    return list(arr)


def square_numbers(array):
    n = len(array)
    arr = (c_int * n)(*array)
    n_res = (c_int)(0)
    result = _square_numbers(arr, n, n_res)

    arr_res = []
    for i in range(n_res.value):
        arr_res.append(result[i])

    return arr_res


if __name__ == '__main__':
    print ('Shift array:')
    a = list(map(int, input('Enter array: ').split()))
    k = int(input('Shift: '))
    print('Result array: ', shift_array(a, k))

    print('\nFull squares:')
    b = list(map(int, input('Enter array: ').split()))
    print('Result array: ', square_numbers(b))

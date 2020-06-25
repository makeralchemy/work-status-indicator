#!/usr/bin/python
import requests

headers = {
    'Authorization': 'Bearer bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb',
}

data = {
  'arg': 'wsi-test'
}

response = requests.post('https://api.particle.io/v1/devices/dddddddddddddddddddddddd/available', headers=headers, data=data)

print response.status_code
print response.text



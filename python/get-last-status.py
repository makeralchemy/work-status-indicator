#!/usr/bin/python

# GET /v1/devices/{DEVICE_ID}/{VARIABLE}

import requests

headers = {
    'Authorization': 'Bearer bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb',
}

data = {
  'arg': 'wsi-test'
}

response = requests.get('https://api.particle.io/v1/devices/dddddddddddddddddddddddd/last_status', headers=headers, data=data)

print response.status_code
print response.text




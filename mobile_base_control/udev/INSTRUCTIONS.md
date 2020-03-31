### udev

To allow the automated detection of the currently used joysticj copy the contents of the udev folder to the local udev-rules directory:

__commands__:
```
roscd mobile_base_control
sudo cp ./udev/* /etc/udev/rules.d/
```

These rules generate symlinks for the joysticks when plugging them in to `/dev/input/js[nameOfJoystick]` and `/dev/input/event[nameOfJoystick]`.

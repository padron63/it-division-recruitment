## FPP (Fake Policumbent Peripheral)

### Peripheral

The peripheral object will only be used for opening the communication on the
peripheral.

```python
class fpp.Peripheral:

    def __init__(self, device_path):
        """
        Construct a new fpp.Peripheral object

        :param device_path: the path corresponding to the peripheral
        :return: nothing
        """

        self.peripheral = self._open_peripheral(device_path)
        return
```

### Notifier

The Notifier object is a "message distributor", it reads the peripheral and then
sends the read messages to the list of [listeners](#listener).

_Received messages are treated asynchronously by the listeners._

```python
class fpp.Notifier(peripheral, listeners)
```

#### Parameters

- `peripheral`: `fpp.Peripheral` object
- `listeners`: list of `fpp.Listener` object

### Listener

The Listener object serves as a basis for constructing objects around it. It
contains abstract methods to be implemented, such as the `on_message_received`
method.

```python
class fpp.Listener:

    @abstractmethod
    def on_message_received(msg) -> None:
    """
    This method is called to handle the given message.
    :param msg: the delivered message
    """
```
#!/bin/sh -e

RESULT=$(echo "adam" | nc "$1" "$2")
echo "$RESULT" | grep "What say you now?"
echo "$RESULT" | grep "What a ho-hum thing to say."
echo "$RESULT" | grep "Fare thee well."


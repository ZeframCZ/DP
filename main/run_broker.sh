if flock -n -x 8; then
  echo ""
  echo "Starting the broker..."
  echo ""
service mosquitto start
  echo ""
  echo "Broker started  $DATE";
  echo "Broker finished `date +%c`";
else
  echo "Broker still running at $DATE";
fi

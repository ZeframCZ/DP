if flock -n -x 8; then
  echo ""
  echo "Starting logger..."
  echo ""
/root/main/venv/bin/python /root/main/mysql_logger.py
  echo ""
  echo "Logger started  $DATE";
  echo "Logger finished `date +%c`";
else
  echo "Logger is still running at $DATE";
fi
